/*
 * @Author: BilyHurington
 * @Date: 2020-02-12 22:15:17
 * @LastEditors  : BilyHurington
 * @LastEditTime : 2020-02-12 23:30:13
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int T,n;
char s[210],ans[30];
bool hav[30];
vector<int> v[30];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=0;i<30;i++) v[i].clear();
        for(int i=1;i<n;i++){
            v[s[i]-'a'].push_back(s[i+1]-'a');
            v[s[i+1]-'a'].push_back(s[i]-'a');
        }
        for(int i=0;i<26;i++) sort(v[i].begin(),v[i].end()),v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
        // for(int i=0;i<26;i++){
        //     for(int j=0;j<v[i].size();j++) printf("%c",v[i][j]+'a');
        //     printf("\n");
        // }
        int beg=-1;
        bool pd=0,pd1=0;
        for(int i=0;i<26;i++){
            if(v[i].size()!=0) pd1=1;
            if(v[i].size()>2){
                pd=1;
                break;
            }
            if(v[i].size()==1) beg=i;
        }
        if((beg==-1&&pd1)||pd){
            printf("NO\n");
            continue;
        }
        if(!pd1){
            printf("YES\n");
            for(int i=0;i<26;i++) printf("%c",'a'+i);
            printf("\n");
            continue;
        }
        int cnt=0;
        memset(hav,0,sizeof(hav));
        for(int i=beg,j=-1;;){
            int nxt;
            hav[i]=1;
            ans[++cnt]=i+'a';
            if(v[i].size()==1&&i!=beg) break;
            for(int l=0;l<v[i].size();l++){
                if(v[i][l]==j) continue;
                nxt=v[i][l];
            }
            j=i;
            i=nxt;
        }
        printf("YES\n");
        for(int i=0;i<26;i++){
            if(!hav[i]) ans[++cnt]=i+'a';
        }
        for(int i=1;i<=cnt;i++) printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}