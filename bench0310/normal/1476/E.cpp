#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    auto h=[&](string s)->int
    {
        int x=0;
        for(char c:s)
        {
            int val=26;
            if(c!='_') val=(c-'a');
            x=(27*x+val);
        }
        return x;
    };
    auto opt=[&](string s)->vector<int>
    {
        vector<int> v;
        for(int i=0;i<(1<<k);i++)
        {
            string t=s;
            for(int j=0;j<k;j++) if(i&(1<<j)) t[j]='_';
            v.push_back(h(t));
        }
        return v;
    };
    int num_masks=h(string(k,'_'))+1;
    vector<int> mask_id(num_masks,0);
    for(int i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        mask_id[h(s)]=i;
    }
    auto out=[](){cout << "NO\n";exit(0);};
    vector<int> v[n+1];
    vector<int> in(n+1,0);
    while(m--)
    {
        string s;
        int mt;
        cin >> s >> mt;
        vector<int> t=opt(s);
        vector<int> id;
        for(int x:t) if(mask_id[x]!=0) id.push_back(mask_id[x]);
        int a=-1;
        for(int i=0;i<(int)id.size();i++) if(id[i]==mt) a=i;
        if(a==-1) out();
        for(int to:id)
        {
            if(to!=mt)
            {
                v[mt].push_back(to);
                in[to]++;
            }
        }
    }
    queue<int> q;
    vector<int> res;
    for(int i=1;i<=n;i++) if(in[i]==0) q.push(i);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        res.push_back(a);
        for(int to:v[a])
        {
            in[to]--;
            if(in[to]==0) q.push(to);
        }
    }
    if((int)res.size()==n)
    {
        cout << "YES\n";
        for(int a:res) cout << a << " ";
        cout << "\n";
    }
    else out();
    return 0;
}