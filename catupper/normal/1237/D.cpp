#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

multiset<int> music;
int n;
int a[660000];
int main(){
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%d", &a[i]);
        a[i+n+n]=a[i+n] = a[i];
    }
    for(int l = 0, r = 0;l < n;l++){
        while(music.empty() || a[r] * 2 >= *music.rbegin()){
            music.insert(a[r++]);
            if(r-l > n + n){
                for(int i = 0;i < n;i++)printf("-1 ");
                printf("\n");
                return 0;
            }
        }
        printf("%d ",r-l);
        music.erase(music.lower_bound(a[l]));
    }
    printf("\n");
    return 0;
}