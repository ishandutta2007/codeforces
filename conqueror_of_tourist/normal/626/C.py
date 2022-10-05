t2, t3 = list(map(int,input().split(' ')))

left = 2*(t2)-10
right = 3*(t2+t3)+10
while right-left != 1:
    guess = int((left+right)/2)
    work2 = int(guess/2)-int(guess/6)
    work3 = int(guess/3)-int(guess/6)
    work6 = int(guess/6)
    if max(0,t2-work2)+max(0,t3-work3) <= work6:
        right = guess
    else:
        left = guess
print(right)