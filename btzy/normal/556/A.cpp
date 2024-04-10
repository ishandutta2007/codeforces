#include<cstdio>
using namespace std;
int n;
char arr[200000];
int ptr=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf(" %c",&arr[ptr]);
        ++ptr;
        while(ptr>1&&arr[ptr-1]!=arr[ptr-2]){
            ptr-=2;
        }
    }
    printf("%d\n",ptr);
}