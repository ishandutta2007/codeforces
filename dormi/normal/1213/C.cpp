#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        lli n,m;
        cin>>n>>m;
        set<lli> used;
        vector<lli> red;
        lli sum=0;
        lli real=m;
        m%=(lli)10;
        lli og=m;
        used.insert(m);
        red.push_back(m);
        sum+=m;
        m=(m+og)%(lli)10;
        while(!used.count(m)){
	        used.insert(m);
	        red.push_back(m);
	        sum+=m;
	        m=(m+og)%(lli)10;
        }
        lli am=n/real;
        lli ans=am/(lli)red.size()*sum;
        for(lli i=0;i<am%(lli)red.size();i++){
        	ans+=red[i];
        }
        printf("%lli\n",ans);
    }
    return 0;
}