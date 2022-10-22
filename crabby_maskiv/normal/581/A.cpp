#include<bits/stdc++.h>
using namespace std;
const int maxn=(1<<12);
const int inf=0x3f3f3f3f;
typedef long long ll;
int a,b;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    cin>>a>>b;
    cout<<min(a,b)<<" "<<(max(a,b)-min(a,b))/2;
	return 0;
}