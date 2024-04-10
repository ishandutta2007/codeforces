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
		int uno=0,zero=0;
		for(int i=0;i<N;i++){
      if(a[i]=='z')zero++;
      if(a[i]=='n')uno++;
		}
		for(int i=0;i<uno;i++)cout<<"1 ";
		for(int i=0;i<zero;i++)cout<<"0 ";
		return 0;
}