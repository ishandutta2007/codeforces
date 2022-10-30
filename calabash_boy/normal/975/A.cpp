#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+100;
int n;
set<int> exist;
int used[300];
char s[maxn];
int main(){
    scanf("%d",&n);
    for (int j=0;j<n;j++){
        scanf("%s",s);
        int len = strlen(s);
        for (int i='a';i<='z';i++){
            used[i]=false;
        }
        for (int i=0;i<len;i++){
            used[s[i]]=true;
        }
        int temp = 0;
        for (int i='a';i<='z';i++){
            if (used[i]){
                temp+= 1<<(i-'a'+1);
            }
        }
        exist.insert(temp);
    }
    cout<<exist.size()<<endl;
    return 0;
}