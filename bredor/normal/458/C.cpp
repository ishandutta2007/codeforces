#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int _D = 100000;
int n;

struct voter
{
//public:
    int deputat;
    int cost;
    int ID;
    bool used;
    
    voter()
    {
        used = false;
    }

    voter(int d, int c, int id, bool u)
    {
         deputat = d;
         cost = c;
         ID = id;
         used = u;
    }

};

vector<vector<voter> > Dep;
vector<pair<int, int> > Map_Dep;
vector<voter> Electorate;
vector<int> Map_Electorate;

bool cmp(voter x, voter y)
{
    return (x.cost < y.cost);
}

bool cmpreverse(voter x, voter y)
{
    return (x.cost >y.cost);
}

void Init()
{
    cin >> n;
    Dep.resize(_D + 1);
    Map_Dep.resize(n);
    //Electorate.resize(n);
    Map_Electorate.resize(n);

    for(int i = 0; i<n; ++i)
    {
        int deputat;
        int cost;
        cin >> deputat >> cost;
        Electorate.push_back(voter(deputat, cost, i, false));
    }

    sort(Electorate.begin(), Electorate.end(), cmp);

    for(int i = 0; i<n; ++i)
        Map_Electorate[Electorate[i].ID] = i;

    for(int i = 0; i<n; ++i)
        Dep[Electorate[i].deputat].push_back(Electorate[i]);

    for(int i = 0; i<=_D; ++i)
        sort(Dep[i].begin(), Dep[i].end(), cmpreverse);

    for(int i = 0; i<=_D; ++i)
    {
        for(int j = 0; j<Dep[i].size(); ++j)
        Map_Dep[Dep[i][j].ID] = make_pair(i, j);
    }

}

class Fenvik
{

    int size;
    vector<int>g;
public:
    Fenvik(){};

    void Make_Tree(int N)
    {
        size = N;
        g.assign(size, 0);
    }

    void Update(int x, int value)
    {
        while(x < size)
        {
            g[x] += value;
            x = x|(x + 1);
        }
    }

    int Ask(int x)
    {
        int ans = 0;
        while(x >= 0)
        {
            //cerr << " x: " << x << "\n";
            int e = x&(x + 1);
            //cerr << e << "\n";
            ans += g[x];
            x = e - 1;
            //cerr << x << "\n";
        }
        return ans;
    }

    int Ask(int l, int r)
    {
        return Ask(r) - Ask(l - 1);
    }

};

Fenvik F_units;
Fenvik F_costs;

int taken;
int yetcost;
priority_queue<pair<int, int> > Q;

void Preparing()
{
    taken = 0;  
    yetcost = 0;
    F_units.Make_Tree(n);
    F_costs.Make_Tree(n);

    for(int i = 0; i<n; ++i)
        F_units.Update(i, 1);

    for(int i = 0; i<n; ++i)
        F_costs.Update(i, Electorate[i].cost);
    //cerr << "mehere\n";
    for(int i = 0; i <= _D; ++i)
    {   
        if (Dep[i].size() > 0)
            Q.push(make_pair(Dep[i].size(), i));
    }

    //cerr << "done\n";

}

int Bin(int Units)
{
    //cerr << "Units: " << Units << "\n";
    
    int R = n;
    int L = 0;
    while(L < R)
    {
        //cerr << L << " " << R << "\n";
        int M = (L + R)/2;
        if (F_units.Ask(0, M - 1)>= Units)
            R = M;
        else
            L = M + 1;
    }
    //cerr << " got: "  << R << "\n";
    return R;

}



int Try(int K)
{

    /*for(int i = 1; i <= _D; ++i)
    {
        while(Dep[i].size() >= K)
        {
            
            int id = Dep[i][Dep[i].size() - 1].ID;
            yetcost += Dep[i][Dep[i].size() - 1].cost;
            Dep[i].pop_back();
            int el = Map_Electorate[id];
            F_units.Update(el, 0);
            F_costs.Update(el, 0);
            ++taken;
        }
    }*/
    //cerr << "try K " << K << "\n";
    while((Q.top()).first >= K)
    {
        //cerr << "Q " << Q.top().first << " " << Q.top().second << "\n";
        int i = Q.top().second;
        Q.pop();
        while(Dep[i].size() >= K)
        {
            
            int id = Dep[i][Dep[i].size() - 1].ID;
            yetcost += Dep[i][Dep[i].size() - 1].cost;
            Dep[i].pop_back();
            int el = Map_Electorate[id];
            F_units.Update(el, -1);
            F_costs.Update(el, -Electorate[el].cost);
            ++taken;
        }
        Q.push(make_pair(Dep[i].size(), i));
    }

    //cerr << "deps ok\n";
    int ans = yetcost;
    //cerr << yetcost << "  - yetcost\n";
    int to_taken = 0;
    if(taken < K)
    {
        int end = Bin(K - taken);// cerr << "bin ok\n";cerr << end << " end\n";
        to_taken =  F_units.Ask(0, end - 1);//cerr << "units ok\n";
        ans += F_costs.Ask(0, end - 1);//cerr << "costs ok\n";
    }
    
    //cerr << ans - yetcost << "  - binchik\n";
    //cerr << taken << "\n"; cerr << to_taken << "\n"; cerr << K << "\n";
    if (taken + to_taken >= K)
        return ans;

    //cerr << "stillb ok\n";

    return 1000000001;

}

int main()
{
    //freopen("input.txt", "r", stdin);
    Init();// cerr << "ok init\n";
    Preparing();//cerr << "ok preparing\n";

    int bestans = 1000000001;

    for(int K = n; K >= 1; --K)
    {//cerr << "start " << K << "\n";
        int curans = Try(K);
        //cerr << curans << "\n";
        if (bestans > curans)
            bestans = curans;
    }

    cout << bestans;

    return 0;
}