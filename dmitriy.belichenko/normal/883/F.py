n = int(input())

s = set()

for i in range(n):
    cur = input()
    ref = ''
    for c in cur:
        if c == 'u':
            ref = ref + 'oo'
        else:
            ref = ref + c
    while True == True:
        check = True
        tmp = ''
        for c in range(0, len(ref)):
            if c != len(ref) - 1 and ref[c] == 'k' and ref[c + 1] == 'h':
                check = False
            else:
                tmp = tmp + ref[c]
        ref = tmp
        if check == True:
            break
    s.add(ref)
print(len(s))