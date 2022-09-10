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
string r[10];
int ll[10],rr[10];
map<string,int>ha[10][2001];
int main(){
    int i,j,k,n,an=0;
    string str;
    cin>>str;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>r[i]>>ll[i]>>rr[i];
        for(j=1;j<=r[i].size();j++)
            for(k=0;k+j<=r[i].size();k++)ha[i][j][r[i].substr(k,j)]++;
    }
    for(i=1;i<=(int)str.size();i++){
        set<string>H;
        for(j=0;j+i<=(int)str.size();j++)H.insert(str.substr(j,i));
        set<string>::iterator it;
        for(it=H.begin();it!=H.end();it++){
            for(j=0;j<n;j++){
                int tmp=ha[j][i][*it];
                if(tmp<ll[j]||tmp>rr[j])break;
            }
            if(j==n)an++;
        }
    }
    printf("%d\n",an);
    return 0;
}