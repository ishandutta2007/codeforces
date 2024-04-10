#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int a[10];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='2'){a[2]+=1;a[3]+=0;a[5]+=0;a[7]+=0;}
        if(s[i]=='3'){a[2]+=1;a[3]+=1;a[5]+=0;a[7]+=0;}
        if(s[i]=='4'){a[2]+=3;a[3]+=1;a[5]+=0;a[7]+=0;}
        if(s[i]=='5'){a[2]+=3;a[3]+=1;a[5]+=1;a[7]+=0;}
        if(s[i]=='6'){a[2]+=4;a[3]+=2;a[5]+=1;a[7]+=0;}
        if(s[i]=='7'){a[2]+=4;a[3]+=2;a[5]+=1;a[7]+=1;}
        if(s[i]=='8'){a[2]+=7;a[3]+=2;a[5]+=1;a[7]+=1;}
        if(s[i]=='9'){a[2]+=7;a[3]+=4;a[5]+=1;a[7]+=1;}
    }
    while(a[7]--){
        a[5]--;
        a[3]-=2;
        a[2]-=4;
        cout<<7;
    }
    while(a[5]--){
        a[3]-=1;
        a[2]-=3;
        cout<<5;
    }
    while(a[3]--){
        a[2]-=1;
        cout<<3;
    }
    while(a[2]--){
        cout<<2;
    }
    cout<<endl;

    return 0;
}