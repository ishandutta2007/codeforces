#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define inpt(n) int n;cin>>n;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    inpt(n);inpt(k);
    for(int i=1;i<=2*n;i++){
        int r;
        if(k==0)
            r=i;
        else{
            if(i%2)r=i+1;
            else {r=i-1;k--;}
        }
        cout<<r<<" ";
    }
}