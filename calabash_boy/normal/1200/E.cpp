#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
//extend[i] = LCP(S[i,lens],T)
//require: nxt[i] = LCP(T[i,lent],T)
//tips:
void exkmp(char *s,int lens,char *t,int lent,int *extend,int *nxt){
   // memset(extend,0,sizeof(int) * (lens+2));
    extend[0] = 0;
    for (int i = 1,p0 = 0,p = 0;i <= lens;i ++){
        extend[i] = i <= p ? min(nxt[i - p0 + 1], p - i + 1) : 0;
        while (i + extend[i] <= lens and extend[i] < lent and s[i + extend[i]] == t[extend[i]+1])extend[i] ++;
        if (i + extend[i] - 1 >= p and i != 1)p0 = i,p = i + extend[i] - 1;
    }
}
char s[maxn],t[maxn];
int extend[maxn];
int nxt[maxn];
int main(){
//    freopen("input.in","r",stdin);
//    freopen("output.out","w",stdout);
    int n;
    scanf("%d",&n);
    s[1] = '*';
    int LEN = 0;
    for (int i=1;i<=n;i++){
        scanf("%s",t+1);
        int lent = strlen(t+1);
        int lens = min(LEN,lent);
       // cerr<<"s:"<<s+LEN-lens+1<<endl;
       // cerr<<"t:"<<t+1<<endl;
        exkmp(t,lent,t,lent,nxt,nxt);
        exkmp(s + LEN - lens,lens,t,lent,extend,nxt);
       // for (int j=1;j<=lent;j++)cerr<<"nxt["<<j<<"]="<<nxt[j]<<endl;
       // for (int j=1;j<=lens;j++)cerr<<"extend["<<j<<"]="<<extend[j]<<endl;
        int sp = 0;
        for (int j = 1;j <= lens;j ++){
            if (lens - j + 1 == extend[j]){
                sp = extend[j];
                break;
            }
        }
        strcpy(s + LEN+1,t + sp + 1);
        LEN += lent - sp;
    }
    printf("%s\n",s+1);
    return 0;
}
/*
 * 11001010 1010100100 0100110010001010 10110111010011 01011101101
 *
 * 11001010 1001001100100010101101
 * 11001010 0100110010001010110111
 *
 *
 */