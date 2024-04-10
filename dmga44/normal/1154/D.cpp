#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define MAXN 200005

int x[MAXN];
int n,a,b;

//bool check(int u)
//{
//    int p=u-a-b;
//    if(p>a)
//        return 0;
//    int pa=a,pb=b;
//    for(int i=0;i<u;i++)
//    {
//        if(!pa && !pb)
//            return 0;
//        if(!x[i])
//        {
//            if(pb)
//                pb--;
//            else
//                pa--;
//        }
//        else
//        {
//            if()
//        }
//    }
//    return 1;
//}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    for(int i=0;i<n;i++)
        cin >> x[i];

    int pa=a,pb=b,res=n;
    for(int i=0;i<n;i++)
    {
        if(!pa && !pb)
        {
            res=i;
            break;
        }
        if(!x[i])
        {
            if(pb)
                pb--;
            else
                pa--;
        }
        else
        {
            if(pa && pb<b)
            {
                pa--;
                pb++;
            }
            else
                pb--;
        }
    }
    db(res)

    return 0;
}