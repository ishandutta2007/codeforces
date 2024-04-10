#include<algorithm>
using namespace std;
vector<int> e[1000000];
main(){
    int n,m,an=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<e[i].size();j++){
            if(e[i][j]<i)m++;
            else m--;
        }
        if(!m)an++;
    }
    printf("%d",an);
}