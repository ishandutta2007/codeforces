//  228

#include<bits/stdc++.h> //Mr_Mandal
#define PI_INT 3.14159265358979323846
#define PI acos(-1.0)
#define LL long long
#define N 100000007
#define MOD 10000007
#define MX numeric_limits<long long>::max();
#define MN numeric_limits<long long>::min();
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define FILL(v, n) fill(v.begin(), v.end(), n);
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PRINT(v) for(int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<"\n";
#define RPRINT(v) for(int i=v.size()-1; i>=0; i--) cout<<v[i]<<" "; cout<<"\n";
#define SCAN(v) for(int i=0; i<n; i++) { int temp; cin>>temp; v.push_back(temp); }
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVE(v) reverse(v.begin(), v.end());
#define VECT(v) vector<int>v
#define SCF(f) scanf("%d", &f)
#define PNF(f) printf("%d\n", f)
#define CASEP(v) cout<<"Case "<<c<<": "<<v<<"\n"
#define TPOW(n) 1LL<<n;

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    VECT(v1);
    VECT(v2);

    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;

        if(a<b)
        {
            v1.push_back(a);
            v2.push_back(b);
        }

        else
        {
            v1.push_back(b);
            v2.push_back(a);
        }
    }

    SORT(v1);
    SORT(v2);

    int Mv1=v1.back();
    int Mv2=v2.front();

    if(Mv1>Mv2)
    {
        cout<<"-1\n";
        return;
    }

    if(Mv1<=m && Mv2>=m)
    {
        cout<<"0\n";
        return;
    }

    if(Mv2<m)
    {
        cout<<m-Mv2<<"\n";
        return;
    }

    if(Mv2>=m)
    {
        cout<<Mv1-m<<"\n";
        return;
    }
}

int main()
{

//#ifndef ONLINE_JUDGE
//    READ("input.txt");
//    WRITE("output.txt");
//#endif

    FAST_IO;

    solve();

    return 0;
}