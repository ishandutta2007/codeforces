#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
using namespace std;
set<int> st;
int t[100002],s[100002],n;

int main()
{
    cin>>n;
    FOR(i,n) cin>>t[i];
    s[n]=0;
    REPD(i,n-1,0) s[i]=s[i+1]+t[i];
    int k=0,wyn=0;
    st.clear();
    st.insert(0);
    FOR(i,n)
    {
        k+=t[i];
        st.insert(-2*k);
        int m=*(--st.end());
        wyn=max(wyn,m+max(0,-2*s[i+1]));
    }
    cout<<s[0]+wyn<<endl;
    return 0;
}