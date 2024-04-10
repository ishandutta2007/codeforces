#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int SIZE = 100011;
const int MAX = 1e9;
int mi[SIZE<<2],a[SIZE];
void init(int L,int R,int id){
    mi[id]=MAX;
    if(L==R)return;
    int mm=(L+R)>>1;
    init(L,mm,id<<1);
    init(mm+1,R,(id<<1)+1);
}
void ins(int L,int R,int id,int x,int v){
    if(L==R){
        mi[id]=v;
        return;
    }
    int mm=(L+R)>>1;
    if(x<=mm)ins(L,mm,id<<1,x,v);
    else ins(mm+1,R,(id<<1)+1,x,v);
    mi[id]=min(mi[id<<1],mi[(id<<1)|1]);
}
int qq(int L,int R,int id,int l1,int rr){
    if(L>=l1&&R<=rr)return mi[id];
    if(R<l1||L>rr)return MAX;
    int mm=(L+R)>>1;
    return min(qq(L,mm,id<<1,l1,rr),qq(mm+1,R,(id<<1)|1,l1,rr));
}
int main(){
    int n,s,l;
    scanf("%d%d%d",&n,&s,&l);
    init(0,n,1);
    ins(0,n,1,0,0);
    multiset<int>H;
    int lt=1,an;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[i]=x;
        H.insert(x);
        while(*H.rbegin()-*H.begin()>s){
            H.erase(H.find(a[lt++]));
        }
        if(i-lt+1>=l){
            ins(0,n,1,i,an=qq(0,n,1,lt-1,i-l)+1);
        }
        else an=MAX;
    }
    if(an>=MAX)puts("-1");
    else printf("%d\n",an);
    return 0;
}