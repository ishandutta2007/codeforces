a=input()-1
s=raw_input()
for x in range(a):
    k=raw_input()
    for c in range(len(s)):
        if(k[c]==s[c]):continue
        s=s[:c]
        break

print len(s)