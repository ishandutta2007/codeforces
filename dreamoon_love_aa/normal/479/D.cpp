#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
set<int>H;
vector<int>r;
int n,l,x,y;
bool valid(int tmp){
    return tmp>=0&&tmp<=l;
}
int main(){
    scanf("%d%d%d%d",&n,&l,&x,&y);
    for(int i=0;i<n;i++){
        int ha;
        scanf("%d",&ha);
        H.insert(ha);
    }
    r.push_back(x);
    r.push_back(y);
    bool suc1=false;
    for(set<int>::iterator it=H.begin();it!=H.end();it++){
        int me=*it;
        int nt=me-x;
        if(H.count(nt)){
            suc1=true;
            if(r.size()==2){
                r.clear();
                r.push_back(y);
            }
        }
        else if(valid(nt)){
            if(H.count(nt+y)||H.count(nt-y)){
                if(r.size()==2){
                    r.clear();
                    r.push_back(nt);
                }
            }
        }
        nt=me+x;
        if(H.count(nt)){
            suc1=true;
            if(r.size()==2){
                r.clear();
                r.push_back(y);
            }
        }
        else if(valid(nt)){
            if(H.count(nt+y)||H.count(nt-y)){
                if(r.size()==2){
                    r.clear();
                    r.push_back(nt);
                }
            }
        }
    }
    bool suc2=false;
    for(set<int>::iterator it=H.begin();it!=H.end();it++){
        int me=*it;
        int nt=me-y;
        if(H.count(nt)){
            suc2=true;
            if(r.size()==2){
                r.clear();
                r.push_back(x);
            }
        }
        else if(valid(nt)){
            if(H.count(nt+x)||H.count(nt-x)){
                if(r.size()==2){
                    r.clear();
                    r.push_back(nt);
                }
            }
        }
        nt=me+y;
        if(H.count(nt)){
            suc2=true;
            if(r.size()==2){
                r.clear();
                r.push_back(x);
            }
        }
        else if(valid(nt)){
            if(H.count(nt+x)||H.count(nt-x)){
                if(r.size()==2){
                    r.clear();
                    r.push_back(nt);
                }
            }
        }
    }
    if(suc1&&suc2)r.clear();
    printf("%d\n",(int)r.size());
    for(int i=0;i<r.size();i++){
        printf("%d\n",r[i]);
    }
    return 0;
}