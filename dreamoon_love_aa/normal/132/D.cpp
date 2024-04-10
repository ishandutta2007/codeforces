#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 1000010
char s[SIZE];
int len;
vector<pair<int,int> >an;
int main(){
    int i,j,k;
    gets(s);
    len=strlen(s);
    reverse(s,s+len);
    for(i=0;s[i];i=j){
        if(s[i]=='0'){
            j=i+1;
            continue;
        }
        for(j=i+1;s[j]&&s[j]=='1';j++);
        if(j==i+1)an.pb(make_pair(1,i));
        else{
            if(s[j]&&s[j+1]&&s[j+1]=='1'){
                an.pb(make_pair(-1,i));
                s[j]='1';
            }
            else{
                an.pb(make_pair(-1,i));
                an.pb(make_pair(1,j));
            }
        }
    }
    printf("%d\n",an.size());
    for(i=0;i<an.size();i++){
        printf("%c2^%d\n",an[i].first==1?'+':'-',an[i].second);
    }
    return 0;
}