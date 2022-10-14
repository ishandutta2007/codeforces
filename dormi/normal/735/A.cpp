#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n,k;
bool can[101];
bool done[101];
string in;
bool go(int a){
	if(done[a])return can[a];
	if(in[a]=='#')return false;
	done[a]=true;
	return can[a]=(a+k<n?go(a+k):false)|(a-k>=0?go(a-k):false);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>in;
    can[in.find('G')]=true;
    done[in.find('G')]=true;
    if(go(in.find('T')))printf("YES\n");
    else printf("NO\n");
    return 0;
}