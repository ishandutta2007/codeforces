#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int S[200001],T[200001],P=0;

int alp[26][26],G[26],N[26];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    string s,t;
    int n;
    int i,j,ai,aj;
    scanf("%d",&n);
    cin >> s >> t;

    for(i=0; i<n; i++){
        if(s[i]!=t[i]){
            S[P]=s[i]-'a';
            T[P]=t[i]-'a';
            alp[S[P]][T[P]]++;
            P++;
        }
    }

    bool ans=false;

    for(i=0; i<26; i++){
        for(j=i+1; j<26; j++){
            if(alp[i][j] >= 1 && alp[j][i] >= 1){
                ans=1;
                break;
            }
        }
        if(ans) break;
    }

    if(ans){
        for(ai=0; ai<n; ai++){
            if(s[ai]==i+'a' && t[ai]==j+'a')break;
        }
        for(aj=0; aj<n; aj++){
            if(s[aj]==j+'a' && t[aj]==i+'a') break;
        }
        if(ai>aj){
            int t=ai;
            ai=aj;
            aj=t;
        }
        printf("%d\n",P-2);
        printf("%d %d\n",ai+1,aj+1);
        return 0;
    }

    for(i=0; i<P; i++){
        G[S[i]]++;
        N[T[i]]++;
    }

    for(i=0; i<26; i++){
        if(G[i]>0 && N[i]>0) break;
    }

    if(i<26){
        for(ai=0; ai<n; ai++){
            if(s[ai]!=t[ai] && s[ai] == i+'a') break;
        }
        for(aj=0; aj<n; aj++){
            if(s[aj]!=t[aj] && aj!=ai && t[aj] == i+'a') break;
        }
        if(aj<n){
            if(ai>aj){
                int t=ai;
                ai=aj;
                aj=t;
            }
            printf("%d\n",P-1);
            printf("%d %d\n",ai+1,aj+1);
            return 0;
        }
    }

    printf("%d\n-1 -1\n",P);

    return 0;
}