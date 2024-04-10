a=input()
b=list(raw_input())*a
alphabe='abcdefghijklmnopqrstuvwxyz'
alphabelist=[[] for x in alphabe]
removed=[]
for x in range(len(b)):
    alphabelist[ord(b[x])-97]+=[x]

for x in range(input()):
    c,d=raw_input().split()
    c=int(c)-1
    d=ord(d)-97
    b[alphabelist[d].pop(c)]='!'
print ''.join(b).replace('!','')