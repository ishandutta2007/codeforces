#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
//mt19937 rd(time(NULL));
int arr[MAXN];
vector<int> bits[30];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<30;j++){
            if(arr[i]&(1<<j)){
                bits[j].push_back(i);
            }
        }
    }
    int spec=-1;
    for(int i=29;i>=0;i--){
        if(bits[i].size()==1){
            spec=bits[i][0];
            break;
        }
    }
    vector<int> ans;
    if(spec!=-1)ans.push_back(arr[spec]);
    for(int i=0;i<n;i++){
        if(i!=spec)ans.push_back(arr[i]);
    }
    for(int i:ans)printf("%d ",i);
//    uniform_int_distribution<int> dist(0,10000);
//    int cur=arr[0];
//    for(int i=1;i<n;i++){
//        cur=(cur|arr[i])-arr[i];
//    }
//    printf("\n%d\n",cur);
//    sort(arr,arr+n);
//    best=-1;
//    int arrbest[n];
//    do{
//        cur=arr[0];
//        for(int i=1;i<n;i++){
//            cur=(cur|arr[i])-arr[i];
//        }
//        if(cur>=best){
//            best=cur;
//            for(int i=0;i<n;i++)arrbest[i]=arr[i];
//        }
//        if(cur==2){
//            for(int x:arr)printf("%d ",x);
//            printf("\n");
//        }
//    }while(next_permutation(arr,arr+n));
//    for(int x:arrbest)printf("%d ",x);
//    printf("\n%d\n",best);
    return 0;
}
/*
 * 8
 * 10 10 4 4 3 3 2 2
 */