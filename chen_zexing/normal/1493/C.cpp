#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char s[100005];
int cnt[30],c[30];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        if(n%k){
            puts("-1");
            continue;
        }
        int pos=-1;
        for(int i=0;i<26;i++) cnt[i]=c[i]=0;
        for(int i=1;i<=n;i++){
            cnt[s[i]-'a']++;
            int tot=0;
            for(int j=0;j<26;j++){
                tot+=cnt[j];
                if(cnt[j]%k) tot+=k-cnt[j]%k,c[j]=k-cnt[j]%k;
                else c[j]=0;
            }
            //cout<<tot<<endl;
            if(tot>n){
                pos=i-1;
                break;
            }
            c[25]+=n-tot;
            int now=25,p=i+1,fl=1;
            while(p<=n){
                while(c[now]==0) now--;
                if(now<s[p]-'a'){
                    fl=0;
                    break;
                }
                else if(now>s[p]-'a'){
                    for(int j=i+1;j<=p-1;j++) cnt[s[j]-'a']++;
                    i=p-1;
                    break;
                }
                else c[now]--,p++;
            }
            //cout<<fl<<endl;
            if(p>n) break;
            if(fl==0){
                pos=i-1;
                break;
            }
        }
        if(pos==-1){
            for(int i=1;i<=n;i++) printf("%c",s[i]);
            puts("");
            continue;
        }
        //cout<<pos<<endl;
        for(int i=1;i<=pos;i++) printf("%c",s[i]);
        for(int i=0;i<26;i++) cnt[i]=0;
        for(int i=1;i<=pos;i++) cnt[s[i]-'a']++;
        int nd,c[26],tot;
        for(int j=s[pos+1]-'a'+1;j<26;j++) {
            cnt[j]++;
            tot=0;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] % k) c[i] = k - cnt[i] % k;
                else c[i] = 0;
                tot+=c[i]+cnt[i];
            }
            //cout<<tot<<endl;
            if(tot<=n){
                nd=j;
                break;
            }
            else cnt[j]--;
        }
        //cout<<nd<<endl;
        printf("%c",char(nd+'a'));
        c[0]+=n-tot;
        for(int i=0;i<26;i++)
            for(int j=1;j<=c[i];j++)
                printf("%c",char(i+'a'));
        puts("");
    }
    return 0;
}
//
/// 