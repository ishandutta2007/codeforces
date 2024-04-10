#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin>>n>>s;
    int d[2] = {};
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'z') d[0]++;
        else if(s[i] == 'n') d[1]++;
    }
    for(int i = 1; i >= 0; i--) {
        while(d[i]--) printf("%d ",i);
    }
    return 0;
}