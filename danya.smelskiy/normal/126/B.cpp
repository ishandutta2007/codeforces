#include <bits/stdc++.h>
using namespace std;

string s;
int p[1000001];
map<int,bool> used;
int main(){
    cin>>s;
    for (int i=1;i<s.size();++i){
        int j=p[i-1];
        while (j>0 && s[j]!=s[i]) j=p[j-1];
        if (s[i]==s[j]) ++j;
        p[i]=j;
        if (i!=s.size()-1) used[p[i]]=true;
    }
    int j=p[s.size()-1];
    while (j>0) {
        if (used[j]) {
            for (int i=0;i<j;++i)
                cout<<s[i];
            return 0;
        }
        j=p[j-1];
    }
    cout<<"Just a legend";
}