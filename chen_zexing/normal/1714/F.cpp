#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,x,y,z;
        scanf("%d%d%d%d",&n,&x,&y,&z);
        int f=1;
        if((x+y-z)%2||(x+z-y)%2||(y+z-x)%2){
            puts("NO");
            continue;
        }
        int d1=(x+z-y)/2,d2=(x+y-z)/2,d3=(y+z-x)/2;
        //cout<<d1<<" "<<d2<<" "<<d3<<endl;
        if(d1+d2+d3+1>n||d1<0||d2<0||d3<0) puts("NO");
        else{
            puts("YES");
            if(d1==0){
                int pre=1,now=4;
                for(int i=1;i<d2;i++) printf("%d %d\n",pre,now),pre=now,now++;
                printf("%d %d\n",pre,2);
                pre=1;
                for(int i=1;i<d3;i++) printf("%d %d\n",pre,now),pre=now,now++;
                printf("%d %d\n",pre,3);
                while(now<=n) printf("%d %d\n",1,now),now++;
            }
            else if(d2==0){
                int pre=2,now=4;
                for(int i=1;i<d1;i++) printf("%d %d\n",pre,now),pre=now,now++;
                printf("%d %d\n",pre,1);
                pre=2;
                for(int i=1;i<d3;i++) printf("%d %d\n",pre,now),pre=now,now++;
                printf("%d %d\n",pre,3);
                while(now<=n) printf("%d %d\n",2,now),now++;
            }
            else if(d3==0){
                int pre=3,now=4;
                for(int i=1;i<d2;i++) printf("%d %d\n",pre,now),pre=now,now++;
                printf("%d %d\n",pre,2);
                pre=3;
                for(int i=1;i<d1;i++) printf("%d %d\n",pre,now),pre=now,now++;
                printf("%d %d\n",pre,1);
                while(now<=n) printf("%d %d\n",3,now),now++;
            }
            else{
                int pre=4,now=5;
                for(int i=1;i<d1;i++) printf("%d %d\n",pre,now),pre=now,now++;
                printf("%d %d\n",pre,1);
                pre=4;
                for(int i=1;i<d2;i++) printf("%d %d\n",pre,now),pre=now,now++;
                printf("%d %d\n",pre,2);
                pre=4;
                for(int i=1;i<d3;i++) printf("%d %d\n",pre,now),pre=now,now++;
                printf("%d %d\n",pre,3);
                while(now<=n) printf("%d %d\n",4,now),now++;
            }
        }
    }
    return 0;
}