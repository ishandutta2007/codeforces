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
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string an;
bool valid(string str){
    if(str[2]!='-'||str[5]!='-')return 0;
    int i;
    for(i=0;i<str.size();i++){
        if(i==2||i==5)continue;
        if(str[i]<'0'||str[i]>'9')return 0;
    }
    int dd=(str[0]-'0')*10+str[1]-'0';
    int mm=(str[3]-'0')*10+str[4]-'0';
    int yy=(str[6]-'0')*1000+(str[7]-'0')*100+(str[8]-'0')*10+str[9]-'0';
    if(yy<2013||yy>2015)return 0;
    if(mm<1||mm>12)return 0;
    if(dd<1||dd>d[mm])return 0;
    return 1;
}
int main(){
    int i,j,k,n,ma=0;
    string str;
    cin>>str;
    vector<string>strs;
    for(i=0;i+10<=(int)str.size();i++){
        if(valid(str.substr(i,10)))strs.pb(str.substr(i,10));
    }
    sort(strs.begin(),strs.end());
    for(i=0;i<strs.size();i=k){
        for(k=i+1;k<strs.size()&&strs[k]==strs[i];k++);
        if(k-i>ma){
            ma=k-i;
            an=strs[i];
        }
    }
    cout<<an<<endl;
    return 0;
}