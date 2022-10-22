#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005

int f[MAXN],c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a;
    cin >> n;
    int dif=0,res=0;
    set<int> fs;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(!f[a])
            dif++,c[0]++;
        c[f[a]]--;
        if(!c[f[a]])
            fs.erase(f[a]);
        f[a]++;
        fs.insert(f[a]);
        c[f[a]]++;
        if(i+1==dif || dif==1)
            res=i+1;
        if(fs.size()==2)
        {
            int x=*(fs.begin());
            auto it=fs.begin();
            it++;
            int y=*it;
            if(x==1 && c[1]==1)
                res=i+1;
            else if(y-x==1 && c[y]==1)
                res=i+1;
        }
    }
    db(res)

    return 0;
}