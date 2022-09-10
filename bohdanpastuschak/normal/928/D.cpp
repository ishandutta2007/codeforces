#include <bits/stdc++.h>

using namespace std;

/*


  

1)   

2)                   

3)        

4)             
 _           
 _       (leaf)       (kilk)
 _          
 _ 1 -             (    )
 _ 2 -            (      )
 _        1       2 (      )

 5)         (    )

*/


char ss[300005];   // 
int cnt;                  //   
string s;                //        
int ans;                 //             !!
map<string,bool> was;   //      2        

bool ok_c(char c)  //                /      '
{                           //                                                                        |
          if(c==' ' || c=='\n' || c=='.' || c==',' || c=='?' || c=='!' || c=='\'' || c=='-')
                    return 0;  //    ,   
          return 1;
}

struct item  //  
{
          int next[26];     //         
          int leaf;           // 
          int kilk;            //    
          item()              //  
          {
                    for(int i=0;i<26;i++)
                              next[i]=-1;
                    leaf=0;
                    kilk=0;
          }
};

vector<item> borchik;  //       ...

int pp=1;  //      

void add(string s)  //   
{
          was[s]=1; //    
          int v=0;    //           (        )
          item temp; //  
          for(int i=0;i<s.size();i++)
          {
                    int c=s[i]-'a';  //      
                    if(borchik[v].next[c]==-1) //     
                    {
                              borchik[v].next[c]=borchik.size();  //     
                              borchik[v].leaf=0;   //                       
                              borchik.push_back(temp); //           (     borchik.size()      )
                    }
                    v=borchik[v].next[c]; //    (    )
                    borchik[v].kilk++;    //         (     1)

                    ///cout<<(char)(c+(int)'a')<<":"<< borchik[v].kilk<<endl;
          }
          borchik[v].leaf=1;  //       ()
}

int f(string s) //       
{
          int v=0;              // -
          int p1=-1,p2=-1;  //   
          for(int i=0;i<s.size();i++)
          {
                    int c=s[i]-'a'; //  

                    if(borchik[v].next[c]==-1) //        100%  
                              break;

                    v=borchik[v].next[c]; //      

                    if(borchik[v].kilk==1 && p1==-1)  //          (      )       1     (*)
                              p1=i;  //  1 

                    if(borchik[v].leaf) //        
                              p2=i; //            

          }
          ///cout<<s<<" "<<p1<<" "<<p2<<endl;

          if(p1==-1 || p2==-1) return s.size();  //                     
                                                                 //       -       *

          return min((int)s.size() , (int)s.size()-(p2-p1)+1);  //                      (   )
                                                                                   //         "abc" i "abcd"    "abcdkek"     "abcd"   "abcd"
                                                                                   //                
                                                                                   //   +1     
                                                                                   //  (2-1)     
}

int main()
{
          borchik.resize(1); //       
          while(scanf("%c",&ss[cnt])==1){cnt++;}   //        
          for(int i=0;i<cnt;i++)
                    s+=ss[i];  // 
          for(int i=0;i<cnt;i++)
                    if(!ok_c(s[i]))
                    {
                              ans++;     //    
                              s[i]=' ';   //  
                    }
          stringstream gg(s);    //  
          string cur;    //  
          while(gg>>cur) //  
          {
                    ans+=f(cur); //           
                    if(!was.count(cur))  //          
                              add(cur); //  
          }
          cout<<ans<<endl; 

}