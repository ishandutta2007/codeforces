#include <stdio.h>

int main() {
   int n;
   char str[100000];
   scanf("%d",&n);
   
  scanf("%s%n", str, &n);
     
     int norm[100000];
     for(int i = 0; i < 100000; ++i)
     norm[i] = 1;
      
    for(int i = 0; i < n - 1; ++i)
    {
        if (str[i] == str[i+1])
        {
            if (str[i] == 'a' || str[i] == 'u' || str[i] == 'y' || str[i] == 'i')
            norm[i] = 0;
        }
    }
    
  
    int ind = 0;
    while (ind < n - 1)
    {
        if (str[ind] == str[ind+1])
        {
            if (str[ind] == 'e' || str[ind] == 'o')
            {
                int counter = 0;
                for(int i = ind; i < n; ++i)
                {
                    if(str[i] == str[ind])counter++;
                    else
                    break;
                }
                
                if (counter == 2) ++ind;
                else
                {
                    for(int i = 1; i < counter; ++i)
                    norm[ind+i] = 0;
                    ind += counter;
                }
            
            }
            else
            {
                ++ind;
            }
        }
        else
        {
            ++ind;
        }
    }
   
      
  for(int i = 0; i < n - 1; ++i)
  if (norm[i] ==1)
  printf("%c",str[i]);
  
  return 0;
    
}