#include<stdio.h>
#include<map>
#include<set>
using namespace std;
#define SIZE 100000
#define SMALL 100
int V[SIZE],N;
map<int,int>M;
struct Query{
    int type,x;
    void scan(){
        char s[8];
        scanf("%s",s);
        if(s[0]=='a')type=0;
        else if(s[0]=='d')type=1;
        else type=2;
        if(type<2){
            scanf("%d",&x);
            M[x]=0;
        }
    }
}q[SIZE];
bool exist[SIZE];
long long sum[SIZE/SMALL][5];
int number[SIZE/SMALL];
void print(){
    int i,now=0;
    long long an=0;
    for(i=0;i*SMALL<N;i++){
        an+=sum[i][((2-now)%5+5)%5];
        now+=number[i];
    }
    printf("%I64d\n",an);
}
void del(int x){
    int i,No=x/SMALL,start=No*SMALL,cnt=0;
    exist[x]=0;
    for(i=0;i<5;i++)sum[No][i]=0;
    for(i=0;i<SMALL;i++){
        if(exist[start+i]){
            sum[No][cnt++]+=V[start+i];
            if(cnt==5)cnt=0;
        }
    }
    number[No]--;
}
void add(int x){
    int i,No=x/SMALL,start=No*SMALL,cnt=0;
    exist[x]=1;
    for(i=0;i<5;i++)sum[No][i]=0;
    for(i=0;i<SMALL;i++){
        if(exist[start+i]){
            sum[No][cnt++]+=V[start+i];
            if(cnt==5)cnt=0;
        }
    }
    number[No]++;
}
void Start(int n){
    int i;
    for(i=0;i<n;i++){
        if(q[i].type==2)print();
        else if(q[i].type==1)del(q[i].x);
        else add(q[i].x);
    }
}
main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)q[i].scan();
    map<int,int>::iterator it;
    for(i=0,it=M.begin();it!=M.end();it++,i++){
        it->second=i;
        V[i]=it->first;
    }
    N=i;
    for(i=0;i<n;i++)
        if(q[i].type!=2)q[i].x=M[q[i].x];
    Start(n);
}