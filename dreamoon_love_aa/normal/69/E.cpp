#include<stdio.h>
#include<map>
#include<set>
using namespace std;
map<int,int>H;
set<int>Hash;
int a[100000];
void print(){
    if(Hash.size()==0){
        puts("Nothing");
        return;
    }
    printf("%d\n",*(--Hash.end()));
}
void remove(int x){
    H[x]--;
    if(H[x]==0)Hash.erase(x);
    else if(H[x]==1)Hash.insert(x);
}
void add(int x){
    if(H.count(x)){
        H[x]++;
        if(H[x]==1)
            Hash.insert(x);
        else if(H[x]==2)Hash.erase(x);
    }
    else{
        H[x]=1;
        Hash.insert(x);
    }
}
main(){
    int i,n,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<k;i++){
        add(a[i]);
    }
    print();
    for(;i<n;i++){
        add(a[i]);
        remove(a[i-k]);
        print();
    }
}