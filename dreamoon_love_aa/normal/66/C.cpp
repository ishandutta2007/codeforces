#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<set>
using namespace std;
int folder_n;
struct Folder{
    vector<Folder*>folder;
    map<string,int>h;
    set<string>file;
    int subfolder_n,file_n;
}folder[10000];
struct Disk{
    vector<Folder*>folder;
    map<string,int>h;
}disk[5];
main(){
    char s[9999],c;
    int head,i,j,*ptr1,*ptr2,an1=0,an2=0;
    while(gets(s)!=NULL){
        head=s[0]-'C';
        i=3;
        for(j=i;s[j]!='\\'&&s[j];j++);
        c=s[j];
        s[j]=0;
        Folder *ptr;
        if(!disk[head].h.count(s+i)){
            disk[head].h[s+i]=disk[head].folder.size();
            disk[head].folder.push_back(&folder[folder_n]);
            folder[folder_n].subfolder_n=folder[folder_n].file_n=0;
            folder_n++;
        }
        ptr=disk[head].folder[disk[head].h[s+i]];
        ptr1=&(ptr->subfolder_n);
        ptr2=&(ptr->file_n);
        s[j]=c;
        i=j;
        while(s[i]){
            i++;
            for(j=i;s[j]!='\\'&&s[j];j++);
            c=s[j];
            s[j]=0;
            if(c){
                if(!(ptr->h).count(s+i)){
                    (*ptr1)++;
                    ptr->h[s+i]=ptr->folder.size();
                    ptr->folder.push_back(&folder[folder_n]);
                    folder_n++;
                }
                ptr=ptr->folder[ptr->h[s+i]];
            }
            else{
                if(!(ptr->file).count(s+i)){
                    (ptr->file).insert(s+i);
                    (*ptr2)++;
                }
            }
            s[j]=c;
            i=j;
        }
        if(an1<*ptr1)an1=*ptr1;
        if(an2<*ptr2)an2=*ptr2;
    }
    printf("%d %d\n",an1,an2);
}