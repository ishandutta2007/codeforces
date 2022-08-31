#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	char a[105],p='0',q='0';
	cin>>a;
	int n=strlen(a),m;
	int x=(a[0]=='-');
	for(m=0;m<n;m++)
        if(a[m]=='.')break;
    if(m+1<n)p=a[m+1];
    if(m+2<n)q=a[m+2];

    if(x)cout<<"(";
    cout<<"$";
    for(int i=x;i<m-1;i++){
        cout<<a[i];
        if((m-i-1)%3==0)cout<<',';
    }
    cout<<a[m-1];
    cout<<'.'<<p<<q;
    if(x)cout<<")";
}