#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
#define REP(i,j) for(int i=0;i<j;i++)
#define REPNM(i,j,k) for(int i=j;i<k;i++)
#define WHILE(n) while(scanf("%d",&n)==1)
#define WHILE_(n) while(scanf("%d",&n)==1 && n)
#define WHILENM(n,m) while(scanf("%d%d",&n,&m)==2)
#define WHILENM_(n,m) while(scanf("%d%d",&n,&m)==2 && n && m)
#define INf 0x3f3f3f3f
#define MEM(i,j) memset(i,j,sizeof i)
#define a first
#define b second
#define pb push_back
#define mp make_pair

/// --------default_code----------
#define MAX 30010
#define INF 0x3f3f3f3f
#define MOD 1000000007
int main()
{
    string s;
    while(cin >> s)
    {
        int q = -1 , ans = -1;
        s+="A";
        REP(i,s.size())
        {
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
            {
                ans = max(ans , i - q);
//                cout<<i - q<<endl;
                q = i;
            }
        }
        cout << ans << endl;
    }

    return 0;
}