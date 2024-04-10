#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 200001
#define BOX 400
int n;
long long a[SIZE],b[SIZE/BOX],mi[SIZE/BOX];
void Add(int v,int left,int right){
    int i,k;
    if(left%BOX){
        while(left%BOX!=0&&left<=right){
            a[left]+=v;
            left++;
        }
        if(left%BOX)k=left/BOX;
        else k=left/BOX-1;
        mi[k]=1000000000000000000ll;
        for(i=k*BOX;i<(k+1)*BOX&&i<n;i++)mi[k]=min(mi[k],a[i]);
    }
    if(right%BOX!=BOX-1&&right>=left){
        while(right%BOX!=BOX-1&&right>=left){
            a[right]+=v;
            right--;
        }
        if(right%BOX!=BOX-1)k=right/BOX;
        else k=right/BOX+1;
        mi[k]=1000000000000000000ll;
        for(i=k*BOX;i<(k+1)*BOX&&i<n;i++)mi[k]=min(mi[k],a[i]);
    }
    if(left>right)return;
    left/=BOX;
    while(left*BOX<right)b[left]+=v,left++;
}
long long Rmq(int left,int right){
    long long an=1000000000000000000ll;
    int i;
    while(left%BOX!=0&&left<=right){
        an=min(an,a[left]+b[left/BOX]);
        left++;
    }
    while(right%BOX!=BOX-1&&right>=left){
        an=min(an,a[right]+b[right/BOX]);
        right--;
    }
    if(left>right)return an;
    left/=BOX;
    while(left*BOX<right)an=min(an,b[left]+mi[left]),left++;
    return an;
}
main(){
    int i,j,x,y,z,m;
    char s[64];
    scanf("%d",&n);
    for(i=0;i*BOX<n;i++)mi[i]=100000000000000000ll;
    for(i=0;i<n;i++)scanf("%I64d",&a[i]),mi[i/BOX]=min(mi[i/BOX],a[i]);
    scanf("%d",&m);
    gets(s);
    for(i=0;i<m;i++){
        gets(s);
        if(sscanf(s,"%d%d%d",&x,&y,&z)==3){
            if(x<=y)Add(z,x,y);
            else Add(z,x,n-1),Add(z,0,y);
        }
        else{
            if(x<=y)printf("%I64d\n",Rmq(x,y));
            else printf("%I64d\n",min(Rmq(x,n-1),Rmq(0,y)));
        }
    }
}