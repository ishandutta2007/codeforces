#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;
int n;
int f[N]; /// f[x] = de cate ori apare valoarea x
int cate[N]; /// cate[x] = pentru cati y : f[y] = x
int penlast;

set <int> s;

bool check(int fr)
{
    if(cate[0]+cate[fr]==(int)1e5 && cate[fr]==1) return 1;
    if(fr==1 && cate[1]+cate[0]==(int)1e5) return 1;
    if(cate[1]==1 && cate[0]+cate[1]+cate[fr]==(int)1e5) return 1;
    int x=cate[fr];
    int y=cate[fr+1];
    int z=cate[0];
    if(x+y+z==(int)1e5 && y==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int res;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cate[0]=(int)1e5;
    s.insert(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(cate[f[x]]==1)s.erase(f[x]);
        cate[f[x]]--;
        f[x]++, cate[f[x]]++;
        if(cate[f[x]]==1)s.insert(f[x]);
        if(s.size()<=4)
        {

            for(auto&x:s)
            {
                if(check(x))
                {
                    res=i;
                    break;
                }
            }
        }
    }
  //  cout<<"\n";
    cout<<res<<"\n";
    return 0;
}
/**

3
1 1 2

7
2 2 1 1 5 4 4

8
2 2 1 1 5 4 4 5

**/