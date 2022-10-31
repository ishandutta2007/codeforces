#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
struct KMP{
    int nxt[maxn];
    int len;
    int t[maxn];
    void clear(){
        len =0;
        nxt[0] = nxt[1] =0;
    }
    /* 1-bas */
    /* ss\0 */
    void init(int * ss,int length){
        len = length;
        memcpy(t,ss,(len+2)*sizeof(int));
        for (int i=2;i<=len;i++){
            nxt[i] = nxt[i-1];
            while (nxt[i]&&ss[i]!=ss[nxt[i]+1]) nxt[i] = nxt[nxt[i]];
            nxt[i]+=(ss[i]==ss[nxt[i]+1]);
        }
    }
    /* ssstart_pos. first_onlytrue*/
    vector<int> match(int *ss,int length,bool first_only = false){
        int len_s = length;
        vector<int> start_pos(0);
        for (int i=1,j=1;i<=len_s;){
            //cerr<<i<<" "<<j<<endl;
            while (j!=1 && ss[i] != t[j])j = nxt[j-1]+1;
            if (ss[i] == t[j]) j++,i++;
            else i++;
            if (j == len+1){
                start_pos.push_back(i-j+1);
                if (first_only)return start_pos;
                j = nxt[len]+1;
            }
        }
        return start_pos;
    }
    void debug(){
        for (int i=0;i<=len;i++){
            printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
//            Debug(nxt[i]);
        }
    }
}kmper;
int a[maxn],b[maxn];
int da[maxn],db[maxn];
int main(){
    int n,w;
    scanf("%d%d",&n,&w);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
        if (i)da[i] = a[i] - a[i-1];
    }
    for (int i=0;i<w;i++){
        scanf("%d",b+i);
        if (i)db[i] = b[i] - b[i-1];
    }
    if (w == 1){
        cout<<n<<endl;
        return 0;
    }
    if (n<w){
        cout<<0<<endl;
        return 0;
    }
    //for (int i=1;i<n;i++){
    //    printf("%d ",da[i]);
    //}
    //puts("");
    //for (int j=1;j<w;j++){
    //    printf("%d ",db[j]);
    //}
    //puts("");
    kmper.init(db,w-1);
    //kmper.debug();
    vector<int> match_pos = kmper.match(da,n-1);
    cout<<match_pos.size()<<endl;
    return 0;
}