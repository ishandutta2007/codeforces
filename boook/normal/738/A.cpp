#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int , int> PII;
#define REP(i,j) for(int i=0;i<j;i++)
#define REPNM(i,j,k) for(int i=j;i<k;i++)
#define RREP(i,j,k) for(int i=j;i>=k;i--)
#define MEM(i,j) memset(i,j,sizeof i)
#define WHILE(n) while(~scanf("%d",&n))
#define WHILE_(n) while(~scanf("%d",&n) && n)
#define WHILENM(n,m) while(~scanf("%d%d",&n,&m))
#define WHILENM_(n,m) while(~scanf("%d%d",&n,&m) && (n || m) )
#define pb push_back
#define mp make_pair
#define A first
#define B second
#define AC 53LL
#define AMOD 1000000079LL
#define debug 0
#define DB() if(debug)
#define RI(i) scanf("%d",&i)

/// ----------- default code ----------------
#define MAX 200500
#define INF 0x3f3f3f3f

int main()
{
    string s;
    int n;
    WHILE(n){
        cin >> s;
        REPNM(i,2,s.size()){
            if(s[i-2]=='o' && s[i-1] == 'g' && s[i]=='o'){
                s[i-2]=s[i-1]=s[i]='*';
                int j = i + 1;
                while( j+1 <s.size()){
                    if(s[j] == 'g' && s[j+1] == 'o')
                        s[j] = s[j+1] = '@';
                    else break;
                    j += 2;
                }
            }
        }
        REP(i,s.size())
            if(s[i]!='@')cout<<s[i];
        cout<<endl;
    }
    return 0;
}