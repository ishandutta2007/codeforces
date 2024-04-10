#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		int N;
		cin>>N;
		string a;
		cin>>a;
		int som1=0,som2=0,vuoti1=0,vuoti2=0;
		for(int i=0;i<N;i++){
			if(i<N/2){
				if(a[i]!='?')som1+=a[i]-'0';
				else vuoti1++;
			}else{
				if(a[i]!='?')som2+=a[i]-'0';
				else vuoti2++;
			}
		}
		if(vuoti1+vuoti2==0){
			if(som1==som2)cout<<"Bicarp";
			else cout<<"Monocarp";
			return 0;
		}
		som1+=vuoti1/2*9;
		som2+=vuoti2/2*9;
		if(som1==som2)cout<<"Bicarp";
		else cout<<"Monocarp";
		return 0;
}