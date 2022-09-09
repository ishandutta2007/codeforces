#include<cstdio>
const int SIZE = 1e6;
char s[SIZE];
int main() {
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d",&n);
        int cc[26]={};
        for(int i=0;i<n;i++){
            scanf("%s",s);
            for(int j=0;s[j];j++){
                cc[s[j]-'a']++;
            }
        }
        int ans=1;
        for(int i=0;i<26;i++){
            if(cc[i]%n)ans=0;
        }
        printf("%s\n",ans?"Yes":"No");
    }
    return 0;
}