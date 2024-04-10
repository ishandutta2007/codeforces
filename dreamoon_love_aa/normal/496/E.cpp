#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int SIZE = 1e5+3;
int an[SIZE];
struct data{
    int L,R,v,id;
    bool operator<(const data& b)const{
        return R<b.R||(R==b.R&&v<b.v);
    }
}a[SIZE*3];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].L,&a[i].R);
        a[i].v=0;
        a[i].id=i;
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a[i+n].L,&a[i+n].R,&a[i+n].v);
        a[i+n].id=i+1;
    }
    sort(a,a+n+m);
    set<pair<int,int> >H;
    for(int i=0;i<n+m;i++){
        if(a[i].v==0){
            H.insert(make_pair(a[i].L,a[i].id));
        }
        else{
            set<pair<int,int> >::iterator it=H.lower_bound(make_pair(a[i].L,0));
            set<pair<int,int> >::iterator it2=it;
            while(it2!=H.end()&&a[i].v>0){
                an[it2->second]=a[i].id;
                it2++;
                a[i].v--;
            }
            H.erase(it,it2);
        }
    }
    if(H.size())puts("NO");
    else{
        puts("YES");
        for(int i=0;i<n;i++){
            if(i)printf(" ");
            printf("%d",an[i]);
        }
        puts("");
    }
    return 0;
}