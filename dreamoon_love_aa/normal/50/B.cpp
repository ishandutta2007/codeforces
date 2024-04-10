#include<iostream>
#include<stdio.h>
using namespace std;
char s[100010];
int cou[128];
main(){
    long long an=0;
    int i;
    gets(s);
    for(i=0;s[i];i++){
        an+=cou[s[i]];
        cou[s[i]]++;
        an+=cou[s[i]];
    }
    cout<<an<<endl;
}