#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int l,r,cur;
string s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    l=0,r=n-1;
    while(l<=r){
        if(a[l]<=cur&&a[r]<=cur)break;
        if(a[l]>cur&&a[r]<=cur){
            cur=a[l];
            l++;
            s+='L';
        }
        if(a[l]<=cur&&a[r]>cur){
            cur=a[r];
            r--;
            s+='R';
        }
        if(a[l]>cur&&a[r]>cur){
            int cl=l,cr=r;
            while(cl<=cr&&a[cl]==a[cr])cl++,cr--;
            if(a[cl]<a[cr]){
                cur=a[cl];
                l=cl+1;
                r=cr;
                s+='L';
            }else{
                cur=a[cr];
                l=cl;
                r=cr-1;
                s+='R';
            }
        }
    }
    cout<<s.size()<<endl<<s<<endl;

    return 0;
}