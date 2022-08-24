n, k = list(map(int, input().split()))
string = input()
good = False
answer = True
counter = 0
while True:
    if counter >= n:
        answer = False
        break
    if not good and string[counter] in "GT":
        good = True
        counter += k
    elif not good:
        counter += 1
    else:
        if string[counter] == "#":
            answer = False
        if string[counter] in "GT":
            break
        counter += k
if answer:
    print("YES")
else:
    print("NO")