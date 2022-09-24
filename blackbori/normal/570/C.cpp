#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    
    cin >> s;
    s = 'a'+s+'a';
    
    int i,remain,consecutive;
    
    remain = consecutive = 0;
    
    for(i=1; i<=n; i++){
        remain += (s[i] == '.');
        consecutive += (s[i] == '.' && s[i-1] != '.');
    }
    
    int idx;
    char chr;
    
    for(i=0; i<m; i++){
        scanf("%d %c",&idx,&chr);
        if(s[idx] != '.' && chr == '.'){
            remain++;
            if(s[idx-1] == '.' && s[idx+1] == '.') consecutive--;
            else if(s[idx-1] != '.' && s[idx+1] != '.') consecutive++;
        }
        else if(s[idx] == '.' && chr != '.'){
            remain--;
            if(s[idx-1] == '.' && s[idx+1] == '.') consecutive++;
            else if(s[idx-1] != '.' && s[idx+1] != '.') consecutive--;
        }
        s[idx] = chr;
        printf("%d\n",remain - consecutive);
    }
    
    
    return 0;
}