#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int getter(char c){
    if(c<='9'){
        return (c-'0');
    }
    else{
        return (c-'A'+10);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char a[10],b[10],z[20],p='\0';
    int c=0,i;
    cin>>z;
    for(i=0;z[i]!=':';i++){
        if(c==0&&z[i]=='0')continue;
        a[c]=z[i];
        if(z[i]>p)p=z[i];
        c++;
    }
    if(c==0){a[0]='0';c++;}
    a[c]='\0';
    c=0;
    for(i++;z[i]!='\0';i++){
        if(c==0&&z[i]=='0')continue;
        b[c]=z[i];
        if(z[i]>p)p=z[i];
        c++;
    }
    if(c==0){b[0]='0';c++;}
    b[c]='\0';
    int x=strlen(a),y=strlen(b);
    if(x==1&&y==1&&a[0]<'O'){cout<<-1;r0;}
    int k=getter(p)+1;
    for(i=k;;i++){
        int h=0,m=0;
        for(int j=0;j<x;j++)h=h*i+getter(a[j]);
        for(int j=0;j<y;j++)m=m*i+getter(b[j]);
        if(h>23||m>59)break;
        cout<<i<<" ";
    }
    if(i==k){
        cout<<"0";
    }
}