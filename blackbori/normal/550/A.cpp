#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> s;

    int i,f1=0,f2=0;

    for(i=1; i<s.size(); i++){
        if(f1==0){
            if(s[i] == 'B' && s[i-1] == 'A') f1++, i++;
        }
        else if(s[i] == 'A' && s[i-1] == 'B') f1++;
    }

    for(i=1; i<s.size(); i++){
        if(f2==0){
            if(s[i] == 'A' && s[i-1] == 'B') f2++, i++;
        }
        else if(s[i] == 'B' && s[i-1] == 'A') f2++;
    }

    printf("%s\n",(f1>1||f2>1)?"YES":"NO");

    return 0;
}