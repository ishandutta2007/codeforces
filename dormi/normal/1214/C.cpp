#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string a;
    cin>>a;
    int cnt=0;
    int mi=0;
    for(int i=0;i<n;i++){
    	if(a[i]==')')cnt-=1;
    	else cnt+=1;
    	mi=min(mi,cnt);
    }
    if(cnt==0&&mi>=-1)printf("Yes\n");
    else printf("No\n");
    return 0;
}