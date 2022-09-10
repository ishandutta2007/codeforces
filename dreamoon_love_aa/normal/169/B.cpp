#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
string a,s;
int d[10];
int main(){
    int i,j,k,n;
    cin>>a>>s;
    for(i=0;i<s.size();i++){
        d[s[i]-'0']++;
    }
    for(i=0;i<a.size();i++){
        for(j=9;j>=0;j--){
            if(d[j]&&j>a[i]-'0'){
                a[i]=j+'0';
                d[j]--;
                break;
            }
        }
    }
    cout<<a<<endl;
    return 0;
}