#include<stdio.h>
#include<vector>
using namespace std;
struct data{
    int pos,len,x;
};
vector<data>car;
vector<data>::iterator iter;
main(){
    int L,b,f,n,x,y,i;
    scanf("%d%d%d",&L,&b,&f);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        if(x==1){
            if(car.size()==0){
                if(L>=y){
                    car.push_back((data){0,y,i});
                    puts("0");
                }
                else puts("-1");
                continue;
            }
            if(car[0].pos>=f+y){
                puts("0");
                car.insert(car.begin(),(data){0,y,i});
                continue;
            }
            for(iter=car.begin();iter!=car.end();iter++){
                //printf("%d:%d\n",i,iter->pos);
                if((iter+1)==car.end()){
                    if(L-iter->pos-iter->len>=b+y){
                        printf("%d\n",iter->pos+iter->len+b);
                        car.push_back((data){iter->pos+iter->len+b,y,i});
                        break;
                    }
                    else puts("-1");
                }
                else{
                    if((iter+1)->pos-iter->pos-iter->len>=b+f+y){
                        printf("%d\n",iter->pos+iter->len+b);
                        car.insert(iter+1,(data){iter->pos+iter->len+b,y,i});
                        break;
                    }
                }
            }
        }
        else{
            for(iter=car.begin();iter->x!=y;iter++);
            car.erase(iter);
        }
    }
}