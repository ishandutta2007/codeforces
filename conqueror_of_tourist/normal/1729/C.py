import math
from sys import stdin
input = stdin.readline
#// - remember to add .strip() when input is a string

t = int(input())
alpha = "abcdefghijklmnopqrstuvwxyz"
out = []
for _ in range(t):

  
  s = input().strip()
  p1 = s[0]
  p2 = s[-1]
  new = []
  cost = 0
  cost = (alpha.index(s[0]) - alpha.index(s[-1]))
  for i in range(len(s)):
    new.append(i+1)
    
  if cost <= 0:
    new.sort(key = lambda x: (s[x-1]))
  else:
    new.reverse()
    new.sort(key = lambda x: (s[x-1]))

 
  end = len(s)

  seq = []

  start = False
  
  for i in range(len(new)):
    
    if (new[i] == 1 or new[i] == end) and start == False:

      start = True

    elif (new[i] == 1 or new[i] == end) and start == True:

      break

    elif start == True:

      seq.append(new[i])

  if cost > 0:
    seq.reverse()
  cost = abs(cost)
  seq.insert(0,1)
  seq.append(end)
  
  print(cost,len(seq))
  print(*seq)