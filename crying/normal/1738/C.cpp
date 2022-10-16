__asm__(R"(
	.file	"E.cpp"
	.section	.text$_Z4Readv,"x"
	.linkonce discard
	.globl	_Z4Readv
	.def	_Z4Readv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4Readv
_Z4Readv:
.LFB33:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$1, %esi
	orl	$-1, %edi
.L2:
	call	getchar
	leal	-48(%rax), %edx
	movb	%al, %bl
	cmpb	$9, %dl
	jbe	.L13
	cmpb	$45, %al
	cmove	%edi, %esi
	jmp	.L2
.L13:
	xorl	$48, %ebx
	movsbl	%bl, %ebx
.L9:
	call	getchar
	leal	-48(%rax), %edx
	cmpb	$9, %dl
	ja	.L14
	leal	(%rbx,%rbx), %edx
	xorl	$48, %eax
	leal	(%rdx,%rbx,8), %edx
	movsbl	%al, %ebx
	addl	%edx, %ebx
	jmp	.L9
.L14:
	movl	%ebx, %eax
	imull	%esi, %eax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_Z4Initv,"x"
	.linkonce discard
	.globl	_Z4Initv
	.def	_Z4Initv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4Initv
_Z4Initv:
.LFB36:
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	leaq	f(%rip), %rcx
	movq	$-210, %r10
	leaq	g(%rip), %rbp
	movl	$100, n(%rip)
	movb	$1, f(%rip)
	xorl	%r9d, %r9d
	movb	$1, 1+f(%rip)
	movq	%rcx, %rdi
	movq	%r10, %r12
.L16:
	leaq	210(%r10), %r11
	movq	%r12, %rbx
	leaq	(%rdi,%r10), %rsi
	xorl	%edx, %edx
	subq	%r10, %rbx
	leaq	(%r11,%rbp), %rax
.L30:
	movl	%r9d, %r8d
	orl	%edx, %r8d
	je	.L18
	leaq	(%rdx,%rdx), %r8
	testl	%r9d, %r9d
	movb	$1, 1(%rax)
	movb	$1, 1(%rcx,%r8)
	je	.L19
	cmpb	$0, 1(%rsi,%r8)
	je	.L20
	movb	$1, (%rcx,%r8)
	jmp	.L20
.L19:
	testq	%rdx, %rdx
	je	.L18
.L32:
	cmpb	$0, -1(%rax)
	je	.L22
	movb	$1, (%rcx,%r8)
	jmp	.L22
.L20:
	testq	%rdx, %rdx
	jne	.L32
.L33:
	cmpb	$0, (%rsi,%r8)
	jne	.L23
	movb	$0, 1(%rcx,%r8)
.L23:
	testq	%rdx, %rdx
	jne	.L34
.L35:
	leaq	(%rbx,%rax), %r13
	cmpb	$0, 1(%r13,%r10)
	je	.L25
	movb	$1, (%rax)
.L25:
	testq	%rdx, %rdx
	jne	.L36
.L37:
	leaq	(%rbx,%rax), %r8
	cmpb	$0, (%r8,%r10)
	jne	.L28
	movb	$0, 1(%rax)
.L28:
	testq	%rdx, %rdx
	jne	.L38
.L18:
	incq	%rdx
	addq	$2, %rax
	cmpq	$101, %rdx
	jne	.L30
	incl	%r9d
	addq	$210, %rcx
	movq	%r11, %r10
	cmpl	$101, %r9d
	jne	.L16
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
.L22:
	testl	%r9d, %r9d
	jne	.L33
.L34:
	cmpb	$0, -2(%rcx,%r8)
	jne	.L24
	movb	$0, 1(%rcx,%r8)
.L24:
	testl	%r9d, %r9d
	jne	.L35
.L36:
	cmpb	$0, -1(%rcx,%r8)
	je	.L26
	movb	$1, (%rax)
.L26:
	testl	%r9d, %r9d
	jne	.L37
.L38:
	cmpb	$0, -2(%rax)
	jne	.L18
	movb	$0, 1(%rax)
	jmp	.L18
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "Alice\0"
.LC1:
	.ascii "Bob\0"
	.section	.text$_Z5Solvev,"x"
	.linkonce discard
	.globl	_Z5Solvev
	.def	_Z5Solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5Solvev
_Z5Solvev:
.LFB37:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movl	$0, cnt1(%rip)
	movl	$0, cnt0(%rip)
	call	_Z4Readv
	movl	%eax, n(%rip)
.L47:
	cmpl	$0, n(%rip)
	je	.L53
	call	_Z4Readv
	testb	$1, %al
	jne	.L48
	incl	cnt0(%rip)
	jmp	.L49
.L48:
	incl	cnt1(%rip)
.L49:
	decl	n(%rip)
	jmp	.L47
.L53:
	movslq	cnt0(%rip), %rax
	movslq	cnt1(%rip), %rdx
	leaq	.LC0(%rip), %rcx
	imulq	$105, %rax, %rax
	addq	%rdx, %rax
	leaq	f(%rip), %rdx
	cmpb	$0, (%rdx,%rax,2)
	jne	.L52
	leaq	.LC1(%rip), %rcx
.L52:
	addq	$40, %rsp
	jmp	puts
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB38:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	call	_Z4Initv
	call	_Z4Readv
	movl	%eax, T(%rip)
.L55:
	cmpl	$0, T(%rip)
	je	.L57
	call	_Z5Solvev
	decl	T(%rip)
	jmp	.L55
.L57:
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.globl	T
	.bss
	.align 4
T:
	.space 4
	.globl	cnt1
	.align 4
cnt1:
	.space 4
	.globl	cnt0
	.align 4
cnt0:
	.space 4
	.globl	g
	.align 64
g:
	.space 22050
	.globl	f
	.align 64
f:
	.space 22050
	.globl	n
	.align 4
n:
	.space 4
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef

)");