#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;
vector<string>rat,woman,man,cap;
main(){
    int n,i;
    char s1[99],s2[99];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s%s",s1,s2);
        if(!strcmp(s2,"rat"))rat.push_back(s1);
        else if(!strcmp(s2,"child"))woman.push_back(s1);
        else if(!strcmp(s2,"woman"))woman.push_back(s1);
        else if(!strcmp(s2,"man"))man.push_back(s1);
        else cap.push_back(s1);
    }
    for(i=0;i<rat.size();i++)
        cout<<rat[i]<<endl;
    for(i=0;i<woman.size();i++)
        cout<<woman[i]<<endl;
    for(i=0;i<man.size();i++)
        cout<<man[i]<<endl;
    for(i=0;i<cap.size();i++)
        cout<<cap[i]<<endl;
}