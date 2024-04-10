#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
char s[1100];
vector<int> left,right,ans;
int main() 
{
    scanf("%s",s+1);
    n=strlen(s+1);
    left.clear();
    right.clear();
    ans.clear();
    for(int i=1;i<=n;i++)
        if (s[i]=='(')left.pb(i); else right.pb(i);
    reverse(right.begin(),right.end());
    int m=min(left.size(),right.size());
   // cout<<m<<endl;
    for(int i=m-1;i>=0;i--)
    {
        //cout<<i<<endl;
        if (left[i]<right[i])
        {
            //cout<<"fuck: "<<i<<endl;
            ans.clear();
            for(int j=0;j<=i;j++)ans.pb(left[j]),ans.pb(right[j]);
            sort(ans.begin(),ans.end());
            puts("1");
            cout<<ans.size()<<endl;
            for(auto p:ans)printf("%d ",p); puts("");
            return 0;
        }
    }
    puts("0");
    return 0;
}