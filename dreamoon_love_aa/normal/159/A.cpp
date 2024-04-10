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
#define SIZE 2222
int answer[SIZE][SIZE],No,A[SIZE],B[SIZE],t[SIZE];
string name[SIZE];
map<string,int>H;
int hash(string& str){
    if(!H.count(str)){
        name[No]=str;
        H[str]=No;
        No++;
    }
    return H[str];
}
vector<int>an;
int main(){
    int i,j,k,n,d;
    cin>>n>>d;
    for(i=0;i<n;i++){
        string str1,str2;
        cin>>str1>>str2>>t[i];
        A[i]=hash(str1);
        B[i]=hash(str2);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(i==j)continue;
            if(B[i]==A[j]&&A[i]==B[j]){
                if(t[i]<t[j]&&t[j]-t[i]<=d)answer[A[i]][B[i]]=1;
            }
        }
    for(i=0;i<No;i++)
        for(j=i+1;j<No;j++)
            if(answer[i][j]||answer[j][i]){
                an.pb(i);
                an.pb(j);
            }
    printf("%d\n",(int)an.size()/2);
    for(i=0;i<an.size();i+=2){
        cout<<name[an[i]]<<" "<<name[an[i+1]]<<endl;
    }
    return 0;
}