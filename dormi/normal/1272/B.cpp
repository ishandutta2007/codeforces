#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
map<char,int> cnt;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        string a;
        cin>>a;
        cnt.clear();
        for(int i=0;i<sz(a);i++){
            cnt[a[i]]++;
        }
        int te=min(cnt['L'],cnt['R']);
        int te2=min(cnt['U'],cnt['D']);
        if(te==0||te2==0){
            if(te==0){
                te2=min(te2,1);
                if(te2==2){
                    printf("4\nUDDU\n");
                }
                else if(te2==1)printf("%d\nUD\n",2);
                else printf("0\n");
            }
            else if(te2==0){
                te=min(te,1);
                if(te==2){
                    printf("4\nLRRL\n");
                }
                else if(te==1)printf("%d\nLR\n",2);
                else printf("0\n");
            }
        }
        else{
            printf("%d\n",te*2+te2*2);
            for(int i=0;i<te;i++)printf("L");
            for(int i=0;i<te2;i++)printf("U");
            for(int i=0;i<te;i++)printf("R");
            for(int i=0;i<te2;i++)printf("D");
            printf("\n");
        }
    }
    return 0;
}